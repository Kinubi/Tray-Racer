#include "TrayRacer/Core/Window.h"


#ifdef HZ_PLATFORM_WINDOWS


int main()
{
	TrayRacer::WindowProps* windowprops = new TrayRacer::WindowProps();
	TrayRacer::Window window(*windowprops);

    while (!window.ShouldClose())
    {
		window.OnUpdate();
    }

	return 0;
}


#endif
