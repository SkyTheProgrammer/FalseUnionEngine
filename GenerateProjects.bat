echo deleting build files and projects

rmdir /s /q "bin" 2>nul
rmdir /s /q "bin-int" 2>nul
del /q "FalseUnion.sln" 2>nul
del /q "FalseUnion\FalseUnion.vcxproj" 2>nul
del /q "FalseUnion\FalseUnion.vcxproj.filters" 2>nul
del /q "Sandbox\Sandbox.vcxproj" 2>nul

call vendor\bin\premake\premake5.exe vs2022
PAUSE