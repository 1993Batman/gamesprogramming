#include "stdafx.h"
#include "CppUnitTest.h"
#include"../Spike1Test/Spike1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GridWorldTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ReturnTrueResults)
		{
			// TODO: Your test code here
			string check = checkmove();
			Assert::IsTrue(check.compare(""));
			playermove = "n";
			Assert::IsTrue(input() == "correct");
			update();
			Assert::IsTrue(PlayerPosY = 6);
		}

		TEST_METHOD(TileChecks)
		{
			// TODO: Your test code here
			PlayerPosX = 2;
			PlayerPosY = 7;
			Assert::IsTrue(_map[PlayerPosY][PlayerPosX] == "S");
			
			PlayerPosX = 1;
			PlayerPosY = 1;

			Assert::IsTrue(_map[PlayerPosY][PlayerPosX] == "G");

			PlayerPosX = 3;
			PlayerPosY = 1;

			Assert::IsTrue(_map[PlayerPosY][PlayerPosX] == "D");
			
			PlayerPosX = 0;
			PlayerPosY = 0;

			Assert::IsTrue(_map[PlayerPosY][PlayerPosX] == "#");

			PlayerPosX = 2;
			PlayerPosY = 1;

			Assert::IsTrue(_map[PlayerPosY][PlayerPosX] == " ");
		}

	};
}