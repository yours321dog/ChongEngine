#version 330

const int MAX_LIGHTS = 4;

in vec2 texCoord0;
in vec3 normal0;
in vec3 worldPos0;

struct Attenuation
{
    float constant;
    float linear;
    float exp;
};

struct Light                                                                            
{                                                                                           
    vec3 color;                                                                     
    float ambientIntensity;                                                         
    float diffuseIntensity;      
    vec3 position;                                                                                                                                              
    vec3 direction;                                                                         
    Attenuation atten;
    float cutoff;                                                                           
}; 

uniform int gNumLights;                                                                                                                                                                                                                     
uniform Light gLights[MAX_LIGHTS];                                             
uniform sampler2D gSampler;                                                                 
uniform vec3 gEyeWorldPos;                                                                  
uniform float gMatSpecularIntensity;                                                        
uniform float gSpecularPower; 

vec4 CalcPointLight(Light light, vec3 normal)                                              
{                                                                                           
    vec3 lightDirection = worldPos0 - light.position;                                           
    float distance = length(lightDirection);                                                
    lightDirection = normalize(lightDirection);                                             
    
    vec4 ambientColor = vec4(light.color * light.ambientIntensity, 1.0f);
    float diffuseFactor = dot(normal, -lightDirection);                                     
                                                                                            
    vec4 diffuseColor  = vec4(0, 0, 0, 0);                                                  
    vec4 specularColor = vec4(0, 0, 0, 0);                                                  
                                                                                            
    if (diffuseFactor > 0) {                                                                
        diffuseColor = vec4(light.color * light.diffuseIntensity * diffuseFactor, 1.0f);
                                                                                            
        vec3 vertexToEye = normalize(gEyeWorldPos - worldPos0);                             
        vec3 lightReflect = normalize(reflect(lightDirection, normal));                     
        float specularFactor = dot(vertexToEye, lightReflect);                                      
        if (specularFactor > 0) {                                                           
            specularFactor = pow(specularFactor, gSpecularPower);                               
            specularColor = vec4(light.color * gMatSpecularIntensity * specularFactor, 1.0f);
        }                                                                                   
    }
                           
    float attenuation =  light.atten.constant +                                                 
                         light.atten.linear * distance +                                        
                         light.atten.exp * distance * distance;                                 
                                                                                            
    return (ambientColor + diffuseColor + specularColor) / attenuation;                                                             
}

vec4 CalcLight(Light light, vec3 normal)                                                
{                                                                                           
    vec3 lightToPixel = normalize(worldPos0 - light.position);                             
                     
    if (light.cutoff == -1)
    {
        return CalcPointLight(light, normal);
    }                    
    
    float spotFactor = dot(lightToPixel, light.direction);                                                                                         
    if (spotFactor > light.cutoff) {                                                            
        vec4 color = CalcPointLight(light, normal);                                        
        return color * (1.0 - (1.0 - spotFactor) * 1.0/(1.0 - light.cutoff));                   
    }                                                                                       
    else {                                                                                  
        return vec4(0,0,0,0);                                                               
    }                                                                                       
}

void main()                                                                                 
{                                                                                           
    vec3 normal = normalize(normal0);                                                       
    vec4 totalLight = vec4(0, 0, 0, 0);                                     
                                                                                            
    for (int i = 0; i < gNumLights; i++)
    {                                            
        totalLight += CalcLight(gLights[i], normal);                                
    }                                                                                       
                                                                                            
    gl_FragColor = texture2D(gSampler, texCoord0.xy) * totalLight;                             
}