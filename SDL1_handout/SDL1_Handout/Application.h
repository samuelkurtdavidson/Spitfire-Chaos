#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"
#include "Module.h"
#include "Dummy.h"

#define NUM_MODULES 1

class Application
{
public:

	Module* modules[NUM_MODULES];

public:

	Application()
	{
		modules[0] = new ModuleDummy();
		// TODO 7: Create your new module "DummyESC"
		// it should check if player it ESC key use kbhit()
		// http://www.cprogramming.com/fod/kbhit.html
		
	}

	// INIT all modules
	bool Init() 
	{
		for (int i = 0; i < NUM_MODULES; ++i)
			if (modules[i]->Init() == false)
				return false;
		
		// TODO 5: Make sure that if Init() / PreUpdate/Update/PostUpdate/CleanUp return
		// an exit code App exits correctly.

		return true; 
	}

	// TODO 4: Add PreUpdate and PostUpdate calls

	// UPDATE all modules
	// TODO 2: Make sure all modules receive its update

	update_status Update() {

		for (int i = 0; i < NUM_MODULES; ++i)

			if (modules[i]->PreUpdate() != update_status::UPDATE_CONTINUE)
				return modules[i]->PreUpdate(); // return 2 or 3 for stop or error in Pre

		for (int i = 0; i < NUM_MODULES; ++i)

			if (modules[i]->Update() != update_status::UPDATE_CONTINUE)
				return modules[i]->Update(); // return 2 or 3 for stop or error in Update

		for (int i = 0; i < NUM_MODULES; ++i)
			if (modules[i]->PostUpdate() != update_status::UPDATE_CONTINUE)
				return modules[i]->PostUpdate();  // return 2 or 3 for stop or error in Post

		return update_status::UPDATE_CONTINUE;; //If no issues, return 1
	}

	// EXIT Update 
	// TODO 3: Make sure all modules have a chance to cleanup
	bool CleanUp()
	{

		for (int i = NUM_MODULES - 1; i >= 0; --i) {
			
			if (modules[i]->CleanUp() != true) 
				return false;	
		}


		return true;
	}

};

#endif // __APPLICATION_H__