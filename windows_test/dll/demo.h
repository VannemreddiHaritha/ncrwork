#pragma once
#ifdef DEMO_EXPORTS
#define DEMOAPI extern "C" __declspec(dllexport)
#else
#define DEMOAPI extern "C" __declspec(dllimport)
#endif
DEMOAPI int add(int variable1, int variable2);
DEMOAPI int sub(int variable1, int variable2);
