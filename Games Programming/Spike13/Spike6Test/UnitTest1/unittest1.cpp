#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Spike6Test/GameController.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(CanCreateObjects)
		{
			// TODO: Your test code here
			Player* p = new Player();
			Inventory* i = new Inventory("Null", "Null", "Null");

			Assert::IsTrue(p != nullptr);
			Assert::IsTrue(i != nullptr);
		}

		TEST_METHOD(AddAndRemoveItem)
		{
			// TODO: Your test code here
			Player* p = new Player();
			Inventory* i = new Inventory("Null", "Null", "Null");

			p->AddItem(i);
		
			Assert::IsTrue(!p->inventory.empty());
			Assert::IsTrue(p->inventory.at(0)->ReturnName() == "Null");

			p->RemoveItem(i);
			Assert::IsTrue(p->inventory.empty());
		}
	};
}