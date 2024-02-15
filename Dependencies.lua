
-- Hazel Dependencies

VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Tray Racer/vendor/GLFW/include"
IncludeDir["glm"] = "%{wks.location}/Tray Racer/vendor/glm"
IncludeDir["Glad"] = "%{wks.location}/Tray Racer/vendor/Glad/include"

LibraryDir = {}

Library = {}
Library["WinSock"] = "Ws2_32.lib"
Library["WinMM"] = "Winmm.lib"
Library["WinVersion"] = "Version.lib"
Library["BCrypt"] = "Bcrypt.lib"