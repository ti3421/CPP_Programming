#include "framework.h"

int main()
{
	shared_ptr<World>world = make_shared<World>();
	srand(time(0));

	int i = 1;
	while (true)
	{
		cout << "================Round" << i << "===============" << endl;
		world->Update();

		cout << endl;


		if (world->End())
			break;
		i++;
	}

	return 0;
}