#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Spike7Test/Edges.h"
#include "../Spike7Test/Location.h"
#include "../Spike7Test/Highscore.h"
#include "../Spike7Test/Gameplay.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ZorkishUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(CreateObjects)
		{
			// TODO: Your test code here
			Gameplay* g = new Gameplay();
			HighScore* h = new HighScore();
			Edges* e = new Edges("Null", "Null", "Null", "Null");
			vector<Edges*> ve = vector<Edges*>();
			ve.push_back(e);
			Location* l = new Location("Null", "Null", ve);

			Assert::IsTrue(g != nullptr);
			Assert::IsTrue(h != nullptr);
			Assert::IsTrue(e != nullptr);
			Assert::IsTrue(l != nullptr);
			Assert::IsTrue(ve.size() > 0);
		}

		TEST_METHOD(CreateWorld)
		{
			// TODO: Your test code here
			Gameplay* g = new Gameplay();
			g->setUpLocations();

			Assert::IsTrue(g->currLoc != nullptr);
			Assert::IsTrue(!g->locations.empty());

			g->currLoc = g->locations.at(1);
			Assert::IsTrue(g->currLoc != g->locations.at(0));
		}



	};
}