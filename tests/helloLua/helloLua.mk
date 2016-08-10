##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=helloLua
ConfigurationName      :=Release
WorkspacePath          :=C:/Users/Joe/Desktop/codeliteWorkspace/cpp
ProjectPath            :=C:/Users/Joe/Desktop/codeliteWorkspace/cpp/helloLua
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Joe
Date                   :=21/07/2016
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="helloLua.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)Lua533 
ArLibs                 :=  "libLua533" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)./includes/Lua/ 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -O2 -Wall $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/LuaInterpreter_LuaInterpreter.cpp$(ObjectSuffix) $(IntermediateDirectory)/OpenGLCallInterpreter_OpenGLCallInterpreter.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Release"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/helloLua/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/LuaInterpreter_LuaInterpreter.cpp$(ObjectSuffix): LuaInterpreter/LuaInterpreter.cpp $(IntermediateDirectory)/LuaInterpreter_LuaInterpreter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/helloLua/LuaInterpreter/LuaInterpreter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LuaInterpreter_LuaInterpreter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LuaInterpreter_LuaInterpreter.cpp$(DependSuffix): LuaInterpreter/LuaInterpreter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LuaInterpreter_LuaInterpreter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LuaInterpreter_LuaInterpreter.cpp$(DependSuffix) -MM "LuaInterpreter/LuaInterpreter.cpp"

$(IntermediateDirectory)/LuaInterpreter_LuaInterpreter.cpp$(PreprocessSuffix): LuaInterpreter/LuaInterpreter.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LuaInterpreter_LuaInterpreter.cpp$(PreprocessSuffix) "LuaInterpreter/LuaInterpreter.cpp"

$(IntermediateDirectory)/OpenGLCallInterpreter_OpenGLCallInterpreter.cpp$(ObjectSuffix): OpenGLCallInterpreter/OpenGLCallInterpreter.cpp $(IntermediateDirectory)/OpenGLCallInterpreter_OpenGLCallInterpreter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/helloLua/OpenGLCallInterpreter/OpenGLCallInterpreter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/OpenGLCallInterpreter_OpenGLCallInterpreter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OpenGLCallInterpreter_OpenGLCallInterpreter.cpp$(DependSuffix): OpenGLCallInterpreter/OpenGLCallInterpreter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OpenGLCallInterpreter_OpenGLCallInterpreter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/OpenGLCallInterpreter_OpenGLCallInterpreter.cpp$(DependSuffix) -MM "OpenGLCallInterpreter/OpenGLCallInterpreter.cpp"

$(IntermediateDirectory)/OpenGLCallInterpreter_OpenGLCallInterpreter.cpp$(PreprocessSuffix): OpenGLCallInterpreter/OpenGLCallInterpreter.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OpenGLCallInterpreter_OpenGLCallInterpreter.cpp$(PreprocessSuffix) "OpenGLCallInterpreter/OpenGLCallInterpreter.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


