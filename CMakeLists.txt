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
        Commands/QueryingCommands/SearchCommand.cpp
        Commands/QueryingCommands/SearchCommand.h
        Commands/Options/SearchOptions.cpp
        Commands/Options/SearchOptions.h
        Commands/Options/CreatedOption.cpp
        Commands/Options/CreatedOption.h
        Commands/Options/LastModifiedOption.cpp
        Commands/Options/LastModifiedOption.h
        Commands/Options/DateSpec/DateSpec.cpp
        Commands/Options/DateSpec/DateSpec.h
        Commands/Options/DateSpec/DateSpecOption.cpp
        Commands/Options/DateSpec/DateSpecOption.h
        Commands/Options/SizeSpec/SizeSpec.cpp
        Commands/Options/SizeSpec/SizeSpec.h
        Commands/Options/SizeSpec/SizeSpecOption.cpp
        Commands/Options/SizeSpec/SizeSpecOption.h
        Commands/Options/SizeOption.cpp
        Commands/Options/SizeOption.h
        Commands/Options/MinSizeOption.cpp
        Commands/Options/MinSizeOption.h
        Commands/Options/MaxSizeOption.cpp
        Commands/Options/MaxSizeOption.h
        Commands/Options/ExtensionSpec/ExtSpec.cpp
        Commands/Options/ExtensionSpec/ExtSpec.h
        Commands/Options/ExtOption.cpp
        Commands/Options/ExtOption.h
        Commands/Options/TypeOption.cpp
        Commands/Options/TypeOption.h)
target_link_libraries(indexeur
        Qt5::Core
        Qt5::Sql
)

