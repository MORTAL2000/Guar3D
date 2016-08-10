##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=jsoncpp
ConfigurationName      :=Release
WorkspacePath          :=C:/Users/Joe/Desktop/codeliteWorkspace/cpp
ProjectPath            :=C:/Users/Joe/Desktop/codeliteWorkspace/cpp/jsoncpp
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Joe
Date                   :=24/07/2016
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="jsoncpp.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./includes/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=   $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/source_json_reader.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_json_value.cpp$(ObjectSuffix) $(IntermediateDirectory)/source_json_writer.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "C:\Users\Joe\Desktop\codeliteWorkspace\cpp/.build-release"
	@echo rebuilt > "C:\Users\Joe\Desktop\codeliteWorkspace\cpp/.build-release/jsoncpp"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Release"


./Release:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/source_json_reader.cpp$(ObjectSuffix): source/json_reader.cpp $(IntermediateDirectory)/source_json_reader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/jsoncpp/source/json_reader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_json_reader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_json_reader.cpp$(DependSuffix): source/json_reader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_json_reader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_json_reader.cpp$(DependSuffix) -MM source/json_reader.cpp

$(IntermediateDirectory)/source_json_reader.cpp$(PreprocessSuffix): source/json_reader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_json_reader.cpp$(PreprocessSuffix)source/json_reader.cpp

$(IntermediateDirectory)/source_json_value.cpp$(ObjectSuffix): source/json_value.cpp $(IntermediateDirectory)/source_json_value.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/jsoncpp/source/json_value.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_json_value.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_json_value.cpp$(DependSuffix): source/json_value.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_json_value.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_json_value.cpp$(DependSuffix) -MM source/json_value.cpp

$(IntermediateDirectory)/source_json_value.cpp$(PreprocessSuffix): source/json_value.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_json_value.cpp$(PreprocessSuffix)source/json_value.cpp

$(IntermediateDirectory)/source_json_writer.cpp$(ObjectSuffix): source/json_writer.cpp $(IntermediateDirectory)/source_json_writer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/jsoncpp/source/json_writer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_json_writer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_json_writer.cpp$(DependSuffix): source/json_writer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_json_writer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_json_writer.cpp$(DependSuffix) -MM source/json_writer.cpp

$(IntermediateDirectory)/source_json_writer.cpp$(PreprocessSuffix): source/json_writer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_json_writer.cpp$(PreprocessSuffix)source/json_writer.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


