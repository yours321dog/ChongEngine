/*!
 * \file ChongRenderLagApi.h
 * \date 2015/11/05
 * \author Lv Luan
 * \brief This is the header of ChongRenderLagApi, which provides interface for 
 *		  the engine
 */

namespace cho
{
	namespace core
	{
		//Initial API

		//****************************************************************
		// Method:    CreateViewWindow
		// FullName:  cho::CreateViewWindow
		// Access:    public static 
		// Returns:   void
		// Qualifier:
		// Parameter: int nWindowWidth
		// Parameter: int nWindowLength
		// Parameter: int nWindowPosX
		// Parameter: int nWindowPosY
		// Parameter: char * sWindowName
		// Description: This function is used to create a window
		//****************************************************************
		static void CreateViewWindow(int nWindowWidth = 1024, int nWindowLength = 768, int nWindowPosX = 100,
			int nWindowPosY = 100, char *sWindowName = "ProjectTest");
	}
}
