//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef UNIT_TEST_CONFIGURATION_H
#define UNIT_TEST_CONFIGURATION_H

// Make sure all are enabled for final submission...
//      I grade whatever is set in this file - Keenan

#define GRAD_461_STUDENT    false
#define UNDER_361_STUDENT   true

// set the cutoff number that works on your machine
#define COMBO_CUT_OFF      45


#if GRAD_461_STUDENT && !UNDER_361_STUDENT

#define CreateList_Test_Enable     true
#define Insert_Test_Enable         true
#define Merge_Test_Enable          true
#define Combo_Test_Enable          true
#define WriteToFile_Test_Grad_Enable         true
#define ReadFromFile_Test_Grad_Enable        true
#define WriteToFile_Test_UnderGrad_Enable    false  // <-- Leave setting false
#define ReadFromFile_Test_UnderGrad_Enable   false  // <-- Leave setting false

#elif !GRAD_461_STUDENT && UNDER_361_STUDENT

#define CreateList_Test_Enable               true
#define Insert_Test_Enable                   true
#define Merge_Test_Enable                    true
#define Combo_Test_Enable                    true
#define WriteToFile_Test_Grad_Enable         false  // <-- Leave Setting false
#define ReadFromFile_Test_Grad_Enable        false  // <-- Leave Setting false
#define WriteToFile_Test_UnderGrad_Enable    true
#define ReadFromFile_Test_UnderGrad_Enable   true

#else

#error Define 361 or 461 student

#define CreateList_Test_Enable               false
#define Insert_Test_Enable                   false
#define Merge_Test_Enable                    false
#define Combo_Test_Enable                    false
#define WriteToFile_Test_Grad_Enable         false
#define ReadFromFile_Test_Grad_Enable        false
#define WriteToFile_Test_UnderGrad_Enable    false
#define ReadFromFile_Test_UnderGrad_Enable   false

#endif

#endif

// ---  End of File ---
