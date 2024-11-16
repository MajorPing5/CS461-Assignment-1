#include "pch.h"
#include "CppUnitTest.h"
#include "../DepthFirstSearch.h"
#include "../BreadthFirstSearch.h"
#include "../IDDFS.h"
#include "../BestFirstSearch.h"
#include "../AStarSearch.h"
#include "../CityGraph.h"
#include <iostream>
#include <vector>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{
	class GraphTestFixture {
	protected:
		static CityGraph cityCopy; // Data copy of cityGraph

		static void SetupGraph() {
			if (cityCopy.empty()) {
				
			}
		}
	};

	namespace UtilitiesAndMapping {
	TEST_CLASS(CityGraph) {
public:
	TEST_METHOD(CityGraphInitialization) {
		// Your tests for CityGraph initialization
	}
	// Other methods related to CityGraph
	};

	TEST_CLASS(City) {
public:
	TEST_METHOD(CityDistance) {
		// Your tests for City distance calculation
	}
	// Other methods related to City
	};

	TEST_CLASS(HeuristicCity) {
public:
	TEST_METHOD(HeuristicCalculation) {
		// Your tests for HeuristicCity calculations
	}
	// Other methods related to HeuristicCity
	};
}

	namespace AlgorithmTests
		
		TEST_CLASS(BreadthFirstSearch)
		{
		public:

			TEST_METHOD(ValidBFSPath) {
				// Example test code for BFS
			}
		// Other BFS test methods
		};

		TEST_CLASS(DepthFirstSearch)
		{
		public:
			
			TEST_METHOD(ValidDFSPath) {
				// Example test code for DFS
			}
		// Other DFS test methods
		};

		TEST_CLASS(IDDFS) {
		public:
		TEST_METHOD(ValidIDDFSPath) {
			// Example test code for IDDFS
		}
		// Other IDDFS test methods
		};

		TEST_CLASS(BestFirstSearch) {
		public:
		TEST_METHOD(ValidBestFirstSearchPath) {
			// Example test code for Best First Search
		}
		// Other Best First Search test methods
		};

		TEST_CLASS(AStarSearch) {
		public:
		TEST_METHOD(ValidAStarPath) {
			// Example test code for A* Search
		}
		// Other A* Search test methods
		};
	}


	namespace AlgorithmTests {
		TEST_CLASS(AlgorithmsSuite) {
		public:
			TEST_METHOD(RunAllAlgorithmTests) {
				BreadthFirstSearch bfsTests;
				bfsTests.TestBFSValidPath();

				DepthFirstSearchTests dfsTests;
				dfsTests.TestDFSValidPath();

				IDDFSTests iddfsTests;
				iddfsTests.TestIDDFSValidPath();

				BestFirstSearchTests bfsfTests;
				bfsfTests.TestBestFirstSearchValidPath();

				AStarSearchTests astarTests;
				astarTests.TestAStarSearchValidPath();
			}
		};
	}

	namespace UtilitiesAndMappingTests {
		TEST_CLASS(UtilitiesAndMappingSuite) {
		public:
			TEST_METHOD(RunAllUtilitiesTests) {
				CityGraph cityGraphTests;
				cityGraphTests.TestCityGraphInitialization();

				City cityTests;
				cityTests.TestCityDistance();

				HeuristicCity heuristicCityTests;
				heuristicCityTests.TestHeuristicCalculation();
			}
		};
	}

	namespace MasterTests {
		TEST_CLASS(AllSuites) {
		public:
			TEST_METHOD(RunAllSuites) {
				AlgorithmTests::AlgorithmsSuite algorithms;
				algorithms.RunAllAlgorithmTests();

				UtilitiesAndMappingTests::UtilitiesAndMapping utilities;
				utilities.RunAllUtilities();
			}
		};
	}

