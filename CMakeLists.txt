cmake_minimum_required(VERSION 3.16)
project(ICDecoder)

set(CMAKE_CXX_STANDARD 11)

add_executable(ICDecoder main.cpp IAbstractReader.cpp IAbstractReader.h IDictionary.cpp IDictionary.h ISentenceReader.cpp ISentenceReader.h IWordReader.cpp IWordReader.h INumberReader.cpp INumberReader.h INumberJudger.cpp INumberJudger.h IOperatorReader.cpp IOperatorReader.h ITypeReader.cpp ITypeReader.h ISingleCharReader.cpp ISingleCharReader.h ICharReader.cpp ICharReader.h IStringReader.cpp IStringReader.h IBlockReader.cpp IBlockReader.h ISingleStringReader.cpp ISingleStringReader.h IForReader.cpp IForReader.h IBoolReader.cpp IBoolReader.h IIfAllReader.cpp IIfAllReader.h IWhileReader.h IElseReader.h IElseIfReader.h IIfReader.h IElseReader.cpp ICallReader.cpp ICallReader.h)