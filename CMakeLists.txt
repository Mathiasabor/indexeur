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
        Commands/Options/SearchOptions.cpp
        Commands/Options/SearchOptions.h
        Commands/Options/CreatedOption.cpp
        Commands/Options/CreatedOption.h
        Commands/Options/LastModifiedOption.cpp
        Commands/Options/LastModifiedOption.h
        Commands/Options/DateSpec/DateSpec.cpp
        Commands/Options/DateSpec/DateSpec.h
        Commands/Options/DateSpec/DateSpecOption.cpp
        Commands/Options/DateSpec/DateSpecOption.h)
target_link_libraries(indexeur
        Qt5::Core
        Qt5::Sql
)

