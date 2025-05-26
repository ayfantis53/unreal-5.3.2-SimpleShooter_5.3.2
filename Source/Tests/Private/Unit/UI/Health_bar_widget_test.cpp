// *************************************************************************** //
// ******************** Unreal Engine version 5.3.2 ************************** //
// Simple Shooter ************************************************************ //
// --------------															   //
// Developed by Andrew Yfantis. 											   //
// https://github.com/ayfantis53 											   //
//             																   //
// 2025 																	   //
// *************************************************************************** //

#include "Unit/UI/Health_bar_widget_test.h"


IMPLEMENT_SIMPLE_AUTOMATION_TEST(health_widget_spawn_test, "UEUnitTests.UI.HealthBar.Spawn", 
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

auto health_widget_spawn_test::RunTest(const FString& Parameters) -> bool
{
    //// INITIALIZE ////
    
    // Get viewport and Initialize widget.
    UGameViewportClient* view_port                     = GEngine->GameViewport;
    TSharedPtr<class SSS_Widget_health_bar> widget_ref = SNew(SSS_Widget_health_bar);

    //// TEST ////

    // Test text correct for win.
    TestTrue("Health bar widget created", widget_ref.IsValid());

    //// FINISH ////

    // Finish test.
    return true;
}