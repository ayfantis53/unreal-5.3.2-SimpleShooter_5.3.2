# SIMPLE SHOOTER 5.3.2 (LINUX)
-----------------------------------------------------------------------------------------
---
* Third Person shooter game built in cpp (No Blueprints)


-----------------------------------------------------------------------------------------
# Game Initialization
-----------------------------------------------------------------------------------------
---
* Dependencies
    - Unreal Engine Binaries (need a github account)
        - Navigate to Unreal Github
            > [https://github.com/EpicGames/UnrealEngine/tree/5.3.2-release]
        - Clone specific repo
            ### `git clone git@github.com:EpicGames/UnrealEngine.git`
    - Set [$UNREAL_PATH] env var
        > in `~/.basrc` set path to wherever your binaries are located on your computer
        > export $UNREAL_PATH=<path-to-your-binaries>
    - Build binaries
        ### `./Setup.sh`
        ### `./GenerateProjectFiles.sh`
        ### `Engine/Build/BatchFiles/RunUAT.sh BuildGraph -target="Make Installed Build Linux" -script="Engine/Build`
* Generate necessary files
    - Link Engine to project (Makefile and etc)
        > ### `./run.sh -g`          --OR--       ### `./run.sh --generate`

* Unreal Editor
    - Enable Shader Model 6 (SM6)
        > Project Settings -> Platforms -> Linux -> Targeted RHIs
    - Animation Blueprints have to be found as classes and their paths have to have a "_C" at the end of the reference.


-----------------------------------------------------------------------------------------
# Running Game
-----------------------------------------------------------------------------------------
---
- Compiling and Running Editor
    > ### `./run.sh -c`              --OR--       ### `./run.sh --compile`
    > ### `./run.sh -e`              --OR--       ### `./run.sh --editor`
- Packaging (Development, Shipping,Debug)
    > ### `./run.sh -p <BuildType>`  --OR--       ### `./run.sh --package <BuildType>`
    - Examples:
        > ### `./run.sh -p Development`    
          ### `./run.sh --package Shipping`    
          ### `./run.sh --package Debug`  
- Running packaged game
    > ### `./run.sh -r`              --OR--       ### `./run.sh --run`
    > ### `./run.sh -b`              --OR--       ### `./run.sh --build`
- Cleanup (Binaries, Intermediate, Saved, Build) or all .core crash files
    > ### `./run.sh -x`              --OR--       ### `./run.sh --clean`
    > ### `./run.sh -x all`          --OR--       ### `./run.sh --clean all`


-----------------------------------------------------------------------------------------
# Testing
-----------------------------------------------------------------------------------------
---
- Running Unit tests
    > Single or Groups of tests
    ### `./run.sh -u <TestName>`            --OR--       ### `./run.sh --unit-test<TestName>`
    - Examples:
        > ### `./run.sh -u Pawns`  
          ### `./run.sh -u Pawns.BasePawn`  
          ### `./run.sh -u Pawns.BasePawn.SpawnActor`
    > All tests
    ### `./run.sh -u`                       --OR--       ### `./run.sh --unit-test`

- Running Functional tests
    - Individual tests
        > Single tests Headless
        ### `./run.sh -f <TestName>`        --OR--       ### `./run.sh --func-test <TestName>`
        - Examples:
            > ### `./run.sh -f TT_functional_test_player`
        > Single tests Editor
        ### `./run.sh -f <TestName> EDITOR` --OR--       ### `./run.sh --func-test <TestName> EDITOR`
        - Examples:
            > ### `./run.sh -f TT_functional_test_player/home/ayfantis/Workspace/UNREAL_ENGINE/UE_5.3.2_PROJECTS/ToonTanks_5.3.2/.ignore EDITOR`
    - Every test
        > All tests Headless
        ### `./run.sh -f`                   --OR--       ### `./run.sh -func`
        > All tests Editor
        ### `./run.sh -f EDITOR`            --OR--       ### `./run.sh -func EDITOR`



-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
