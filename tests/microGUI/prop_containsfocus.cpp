#include "./phwidgets_init.cpp"

#include "./testsuit.h"

#include <Widget.h>
#include <photon/PtWindow.h>


TEST_CASE("Testing Widget::ContainsFocus property"){
    REQUIRE(PhWidgetsGetWidget<&PtWindow>());

    using namespace PhWidgets;
    
    Widget widget(PhWidgetsGetWidget<&PtWindow>());

    CHECK(widget.ContainsFocus == false);
}