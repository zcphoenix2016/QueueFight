UTLIB = googletest/build/googlemock/libgmock_main.a\
        googletest/build/googlemock/libgmock.a\
        googletest/build/googlemock/gtest/libgtest.a

UTINC = -isystem googletest/googlemock/include\
       -isystem googletest/googletest/include\

UTFLAG = -g -pthread -DUNIT_TEST -Wno-write-strings

all:
	g++ -std=c++14 Sources/*.cpp -o QueueFight.exe -g

ut:
	g++ -std=c++14 ${UTFLAG} ${UTINC} ${UTLIB} Sources/*.cpp TestCases/*.cpp -o ut_QueueFight.exe

ut_id:
	g++ -std=c++14 ${UTFLAG} ${UTINC} ${UTLIB} Sources/IdGenerator.cpp TestCases/IdGeneratorTests.cpp -o ut_id.exe

clean:
	rm -rf *.o
	rm -rf TestCases/*.o
	rm -rf QueueFight.exe
	rm -rf ut_QueueFight.exe
