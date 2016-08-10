##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Lua533
ConfigurationName      :=Release
WorkspacePath          :=C:/Users/Joe/Desktop/codeliteWorkspace/cpp
ProjectPath            :=C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533
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
ObjectsFileList        :="Lua533.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
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
Objects0=$(IntermediateDirectory)/src_lapi.c$(ObjectSuffix) $(IntermediateDirectory)/src_lauxlib.c$(ObjectSuffix) $(IntermediateDirectory)/src_lbaselib.c$(ObjectSuffix) $(IntermediateDirectory)/src_lbitlib.c$(ObjectSuffix) $(IntermediateDirectory)/src_lcode.c$(ObjectSuffix) $(IntermediateDirectory)/src_lcorolib.c$(ObjectSuffix) $(IntermediateDirectory)/src_lctype.c$(ObjectSuffix) $(IntermediateDirectory)/src_ldblib.c$(ObjectSuffix) $(IntermediateDirectory)/src_ldebug.c$(ObjectSuffix) $(IntermediateDirectory)/src_ldo.c$(ObjectSuffix) \
	$(IntermediateDirectory)/src_ldump.c$(ObjectSuffix) $(IntermediateDirectory)/src_lfunc.c$(ObjectSuffix) $(IntermediateDirectory)/src_lgc.c$(ObjectSuffix) $(IntermediateDirectory)/src_linit.c$(ObjectSuffix) $(IntermediateDirectory)/src_liolib.c$(ObjectSuffix) $(IntermediateDirectory)/src_llex.c$(ObjectSuffix) $(IntermediateDirectory)/src_lmathlib.c$(ObjectSuffix) $(IntermediateDirectory)/src_lmem.c$(ObjectSuffix) $(IntermediateDirectory)/src_loadlib.c$(ObjectSuffix) $(IntermediateDirectory)/src_lobject.c$(ObjectSuffix) \
	$(IntermediateDirectory)/src_lopcodes.c$(ObjectSuffix) $(IntermediateDirectory)/src_loslib.c$(ObjectSuffix) $(IntermediateDirectory)/src_lparser.c$(ObjectSuffix) $(IntermediateDirectory)/src_lstate.c$(ObjectSuffix) $(IntermediateDirectory)/src_lstring.c$(ObjectSuffix) $(IntermediateDirectory)/src_lstrlib.c$(ObjectSuffix) $(IntermediateDirectory)/src_ltable.c$(ObjectSuffix) $(IntermediateDirectory)/src_ltablib.c$(ObjectSuffix) $(IntermediateDirectory)/src_ltm.c$(ObjectSuffix) $(IntermediateDirectory)/src_lundump.c$(ObjectSuffix) \
	$(IntermediateDirectory)/src_lutf8lib.c$(ObjectSuffix) $(IntermediateDirectory)/src_lvm.c$(ObjectSuffix) $(IntermediateDirectory)/src_lzio.c$(ObjectSuffix) 



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
	@echo rebuilt > "C:\Users\Joe\Desktop\codeliteWorkspace\cpp/.build-release/Lua533"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Release"


./Release:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_lapi.c$(ObjectSuffix): src/lapi.c $(IntermediateDirectory)/src_lapi.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lapi.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lapi.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lapi.c$(DependSuffix): src/lapi.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lapi.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lapi.c$(DependSuffix) -MM src/lapi.c

$(IntermediateDirectory)/src_lapi.c$(PreprocessSuffix): src/lapi.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lapi.c$(PreprocessSuffix)src/lapi.c

$(IntermediateDirectory)/src_lauxlib.c$(ObjectSuffix): src/lauxlib.c $(IntermediateDirectory)/src_lauxlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lauxlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lauxlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lauxlib.c$(DependSuffix): src/lauxlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lauxlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lauxlib.c$(DependSuffix) -MM src/lauxlib.c

$(IntermediateDirectory)/src_lauxlib.c$(PreprocessSuffix): src/lauxlib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lauxlib.c$(PreprocessSuffix)src/lauxlib.c

$(IntermediateDirectory)/src_lbaselib.c$(ObjectSuffix): src/lbaselib.c $(IntermediateDirectory)/src_lbaselib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lbaselib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lbaselib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lbaselib.c$(DependSuffix): src/lbaselib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lbaselib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lbaselib.c$(DependSuffix) -MM src/lbaselib.c

$(IntermediateDirectory)/src_lbaselib.c$(PreprocessSuffix): src/lbaselib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lbaselib.c$(PreprocessSuffix)src/lbaselib.c

$(IntermediateDirectory)/src_lbitlib.c$(ObjectSuffix): src/lbitlib.c $(IntermediateDirectory)/src_lbitlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lbitlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lbitlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lbitlib.c$(DependSuffix): src/lbitlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lbitlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lbitlib.c$(DependSuffix) -MM src/lbitlib.c

$(IntermediateDirectory)/src_lbitlib.c$(PreprocessSuffix): src/lbitlib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lbitlib.c$(PreprocessSuffix)src/lbitlib.c

$(IntermediateDirectory)/src_lcode.c$(ObjectSuffix): src/lcode.c $(IntermediateDirectory)/src_lcode.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lcode.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lcode.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lcode.c$(DependSuffix): src/lcode.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lcode.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lcode.c$(DependSuffix) -MM src/lcode.c

$(IntermediateDirectory)/src_lcode.c$(PreprocessSuffix): src/lcode.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lcode.c$(PreprocessSuffix)src/lcode.c

$(IntermediateDirectory)/src_lcorolib.c$(ObjectSuffix): src/lcorolib.c $(IntermediateDirectory)/src_lcorolib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lcorolib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lcorolib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lcorolib.c$(DependSuffix): src/lcorolib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lcorolib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lcorolib.c$(DependSuffix) -MM src/lcorolib.c

$(IntermediateDirectory)/src_lcorolib.c$(PreprocessSuffix): src/lcorolib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lcorolib.c$(PreprocessSuffix)src/lcorolib.c

$(IntermediateDirectory)/src_lctype.c$(ObjectSuffix): src/lctype.c $(IntermediateDirectory)/src_lctype.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lctype.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lctype.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lctype.c$(DependSuffix): src/lctype.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lctype.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lctype.c$(DependSuffix) -MM src/lctype.c

$(IntermediateDirectory)/src_lctype.c$(PreprocessSuffix): src/lctype.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lctype.c$(PreprocessSuffix)src/lctype.c

$(IntermediateDirectory)/src_ldblib.c$(ObjectSuffix): src/ldblib.c $(IntermediateDirectory)/src_ldblib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/ldblib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ldblib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ldblib.c$(DependSuffix): src/ldblib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ldblib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ldblib.c$(DependSuffix) -MM src/ldblib.c

$(IntermediateDirectory)/src_ldblib.c$(PreprocessSuffix): src/ldblib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ldblib.c$(PreprocessSuffix)src/ldblib.c

$(IntermediateDirectory)/src_ldebug.c$(ObjectSuffix): src/ldebug.c $(IntermediateDirectory)/src_ldebug.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/ldebug.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ldebug.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ldebug.c$(DependSuffix): src/ldebug.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ldebug.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ldebug.c$(DependSuffix) -MM src/ldebug.c

$(IntermediateDirectory)/src_ldebug.c$(PreprocessSuffix): src/ldebug.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ldebug.c$(PreprocessSuffix)src/ldebug.c

$(IntermediateDirectory)/src_ldo.c$(ObjectSuffix): src/ldo.c $(IntermediateDirectory)/src_ldo.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/ldo.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ldo.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ldo.c$(DependSuffix): src/ldo.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ldo.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ldo.c$(DependSuffix) -MM src/ldo.c

$(IntermediateDirectory)/src_ldo.c$(PreprocessSuffix): src/ldo.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ldo.c$(PreprocessSuffix)src/ldo.c

$(IntermediateDirectory)/src_ldump.c$(ObjectSuffix): src/ldump.c $(IntermediateDirectory)/src_ldump.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/ldump.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ldump.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ldump.c$(DependSuffix): src/ldump.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ldump.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ldump.c$(DependSuffix) -MM src/ldump.c

$(IntermediateDirectory)/src_ldump.c$(PreprocessSuffix): src/ldump.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ldump.c$(PreprocessSuffix)src/ldump.c

$(IntermediateDirectory)/src_lfunc.c$(ObjectSuffix): src/lfunc.c $(IntermediateDirectory)/src_lfunc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lfunc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lfunc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lfunc.c$(DependSuffix): src/lfunc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lfunc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lfunc.c$(DependSuffix) -MM src/lfunc.c

$(IntermediateDirectory)/src_lfunc.c$(PreprocessSuffix): src/lfunc.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lfunc.c$(PreprocessSuffix)src/lfunc.c

$(IntermediateDirectory)/src_lgc.c$(ObjectSuffix): src/lgc.c $(IntermediateDirectory)/src_lgc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lgc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lgc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lgc.c$(DependSuffix): src/lgc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lgc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lgc.c$(DependSuffix) -MM src/lgc.c

$(IntermediateDirectory)/src_lgc.c$(PreprocessSuffix): src/lgc.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lgc.c$(PreprocessSuffix)src/lgc.c

$(IntermediateDirectory)/src_linit.c$(ObjectSuffix): src/linit.c $(IntermediateDirectory)/src_linit.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/linit.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_linit.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_linit.c$(DependSuffix): src/linit.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_linit.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_linit.c$(DependSuffix) -MM src/linit.c

$(IntermediateDirectory)/src_linit.c$(PreprocessSuffix): src/linit.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_linit.c$(PreprocessSuffix)src/linit.c

$(IntermediateDirectory)/src_liolib.c$(ObjectSuffix): src/liolib.c $(IntermediateDirectory)/src_liolib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/liolib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_liolib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_liolib.c$(DependSuffix): src/liolib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_liolib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_liolib.c$(DependSuffix) -MM src/liolib.c

$(IntermediateDirectory)/src_liolib.c$(PreprocessSuffix): src/liolib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_liolib.c$(PreprocessSuffix)src/liolib.c

$(IntermediateDirectory)/src_llex.c$(ObjectSuffix): src/llex.c $(IntermediateDirectory)/src_llex.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/llex.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_llex.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_llex.c$(DependSuffix): src/llex.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_llex.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_llex.c$(DependSuffix) -MM src/llex.c

$(IntermediateDirectory)/src_llex.c$(PreprocessSuffix): src/llex.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_llex.c$(PreprocessSuffix)src/llex.c

$(IntermediateDirectory)/src_lmathlib.c$(ObjectSuffix): src/lmathlib.c $(IntermediateDirectory)/src_lmathlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lmathlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lmathlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lmathlib.c$(DependSuffix): src/lmathlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lmathlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lmathlib.c$(DependSuffix) -MM src/lmathlib.c

$(IntermediateDirectory)/src_lmathlib.c$(PreprocessSuffix): src/lmathlib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lmathlib.c$(PreprocessSuffix)src/lmathlib.c

$(IntermediateDirectory)/src_lmem.c$(ObjectSuffix): src/lmem.c $(IntermediateDirectory)/src_lmem.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lmem.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lmem.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lmem.c$(DependSuffix): src/lmem.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lmem.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lmem.c$(DependSuffix) -MM src/lmem.c

$(IntermediateDirectory)/src_lmem.c$(PreprocessSuffix): src/lmem.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lmem.c$(PreprocessSuffix)src/lmem.c

$(IntermediateDirectory)/src_loadlib.c$(ObjectSuffix): src/loadlib.c $(IntermediateDirectory)/src_loadlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/loadlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_loadlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_loadlib.c$(DependSuffix): src/loadlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_loadlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_loadlib.c$(DependSuffix) -MM src/loadlib.c

$(IntermediateDirectory)/src_loadlib.c$(PreprocessSuffix): src/loadlib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_loadlib.c$(PreprocessSuffix)src/loadlib.c

$(IntermediateDirectory)/src_lobject.c$(ObjectSuffix): src/lobject.c $(IntermediateDirectory)/src_lobject.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lobject.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lobject.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lobject.c$(DependSuffix): src/lobject.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lobject.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lobject.c$(DependSuffix) -MM src/lobject.c

$(IntermediateDirectory)/src_lobject.c$(PreprocessSuffix): src/lobject.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lobject.c$(PreprocessSuffix)src/lobject.c

$(IntermediateDirectory)/src_lopcodes.c$(ObjectSuffix): src/lopcodes.c $(IntermediateDirectory)/src_lopcodes.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lopcodes.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lopcodes.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lopcodes.c$(DependSuffix): src/lopcodes.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lopcodes.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lopcodes.c$(DependSuffix) -MM src/lopcodes.c

$(IntermediateDirectory)/src_lopcodes.c$(PreprocessSuffix): src/lopcodes.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lopcodes.c$(PreprocessSuffix)src/lopcodes.c

$(IntermediateDirectory)/src_loslib.c$(ObjectSuffix): src/loslib.c $(IntermediateDirectory)/src_loslib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/loslib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_loslib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_loslib.c$(DependSuffix): src/loslib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_loslib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_loslib.c$(DependSuffix) -MM src/loslib.c

$(IntermediateDirectory)/src_loslib.c$(PreprocessSuffix): src/loslib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_loslib.c$(PreprocessSuffix)src/loslib.c

$(IntermediateDirectory)/src_lparser.c$(ObjectSuffix): src/lparser.c $(IntermediateDirectory)/src_lparser.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lparser.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lparser.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lparser.c$(DependSuffix): src/lparser.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lparser.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lparser.c$(DependSuffix) -MM src/lparser.c

$(IntermediateDirectory)/src_lparser.c$(PreprocessSuffix): src/lparser.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lparser.c$(PreprocessSuffix)src/lparser.c

$(IntermediateDirectory)/src_lstate.c$(ObjectSuffix): src/lstate.c $(IntermediateDirectory)/src_lstate.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lstate.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lstate.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lstate.c$(DependSuffix): src/lstate.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lstate.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lstate.c$(DependSuffix) -MM src/lstate.c

$(IntermediateDirectory)/src_lstate.c$(PreprocessSuffix): src/lstate.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lstate.c$(PreprocessSuffix)src/lstate.c

$(IntermediateDirectory)/src_lstring.c$(ObjectSuffix): src/lstring.c $(IntermediateDirectory)/src_lstring.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lstring.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lstring.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lstring.c$(DependSuffix): src/lstring.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lstring.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lstring.c$(DependSuffix) -MM src/lstring.c

$(IntermediateDirectory)/src_lstring.c$(PreprocessSuffix): src/lstring.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lstring.c$(PreprocessSuffix)src/lstring.c

$(IntermediateDirectory)/src_lstrlib.c$(ObjectSuffix): src/lstrlib.c $(IntermediateDirectory)/src_lstrlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lstrlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lstrlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lstrlib.c$(DependSuffix): src/lstrlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lstrlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lstrlib.c$(DependSuffix) -MM src/lstrlib.c

$(IntermediateDirectory)/src_lstrlib.c$(PreprocessSuffix): src/lstrlib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lstrlib.c$(PreprocessSuffix)src/lstrlib.c

$(IntermediateDirectory)/src_ltable.c$(ObjectSuffix): src/ltable.c $(IntermediateDirectory)/src_ltable.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/ltable.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ltable.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ltable.c$(DependSuffix): src/ltable.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ltable.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ltable.c$(DependSuffix) -MM src/ltable.c

$(IntermediateDirectory)/src_ltable.c$(PreprocessSuffix): src/ltable.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ltable.c$(PreprocessSuffix)src/ltable.c

$(IntermediateDirectory)/src_ltablib.c$(ObjectSuffix): src/ltablib.c $(IntermediateDirectory)/src_ltablib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/ltablib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ltablib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ltablib.c$(DependSuffix): src/ltablib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ltablib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ltablib.c$(DependSuffix) -MM src/ltablib.c

$(IntermediateDirectory)/src_ltablib.c$(PreprocessSuffix): src/ltablib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ltablib.c$(PreprocessSuffix)src/ltablib.c

$(IntermediateDirectory)/src_ltm.c$(ObjectSuffix): src/ltm.c $(IntermediateDirectory)/src_ltm.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/ltm.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ltm.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ltm.c$(DependSuffix): src/ltm.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ltm.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ltm.c$(DependSuffix) -MM src/ltm.c

$(IntermediateDirectory)/src_ltm.c$(PreprocessSuffix): src/ltm.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ltm.c$(PreprocessSuffix)src/ltm.c

$(IntermediateDirectory)/src_lundump.c$(ObjectSuffix): src/lundump.c $(IntermediateDirectory)/src_lundump.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lundump.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lundump.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lundump.c$(DependSuffix): src/lundump.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lundump.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lundump.c$(DependSuffix) -MM src/lundump.c

$(IntermediateDirectory)/src_lundump.c$(PreprocessSuffix): src/lundump.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lundump.c$(PreprocessSuffix)src/lundump.c

$(IntermediateDirectory)/src_lutf8lib.c$(ObjectSuffix): src/lutf8lib.c $(IntermediateDirectory)/src_lutf8lib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lutf8lib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lutf8lib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lutf8lib.c$(DependSuffix): src/lutf8lib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lutf8lib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lutf8lib.c$(DependSuffix) -MM src/lutf8lib.c

$(IntermediateDirectory)/src_lutf8lib.c$(PreprocessSuffix): src/lutf8lib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lutf8lib.c$(PreprocessSuffix)src/lutf8lib.c

$(IntermediateDirectory)/src_lvm.c$(ObjectSuffix): src/lvm.c $(IntermediateDirectory)/src_lvm.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lvm.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lvm.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lvm.c$(DependSuffix): src/lvm.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lvm.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lvm.c$(DependSuffix) -MM src/lvm.c

$(IntermediateDirectory)/src_lvm.c$(PreprocessSuffix): src/lvm.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lvm.c$(PreprocessSuffix)src/lvm.c

$(IntermediateDirectory)/src_lzio.c$(ObjectSuffix): src/lzio.c $(IntermediateDirectory)/src_lzio.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Joe/Desktop/codeliteWorkspace/cpp/Lua533/src/lzio.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lzio.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lzio.c$(DependSuffix): src/lzio.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lzio.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lzio.c$(DependSuffix) -MM src/lzio.c

$(IntermediateDirectory)/src_lzio.c$(PreprocessSuffix): src/lzio.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lzio.c$(PreprocessSuffix)src/lzio.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


