cmake_minimum_required(VERSION 3.30)
project(indexeur)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Sql
        REQUIRED)

add_executable(indexeur main.cpp
        Indexer/Indexer.cpp
        Indexer/Indexer.h
        Tokenizer/Tokenizer.cpp
        Tokenizer/Tokenizer.h
        Indexer/IndexerState.h
        DAO/FilesDTO.h
        DAO/DB.cpp
        DAO/DB.h
        DAO/QueryManager.h
        Commands/CommandFactory.cpp
        Commands/CommandFactory.h
        Commands/QueryingCommands/QueryingCommand.cpp
        Commands/QueryingCommands/QueryingCommand.h
        Commands/QueryingCommands/SearchCommand.cpp
        Commands/QueryingCommands/SearchCommand.h
        Commands/AbstractCommand.cpp
        Commands/AbstractCommand.h
        Commands/Options/Options.cpp
        Commands/Options/Options.h
        Commands/Options/SearchOptions.cpp
        Commands/Options/SearchOptions.h
        Commands/Options/Size.cpp
        Commands/Options/Size.h
        Commands/Options/Type.cpp
        Commands/Options/Type.h
)
target_link_libraries(indexeur
        Qt5::Core
        Qt5::Sql
)
