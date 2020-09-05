#include "GameManager\GameManager.h"
#include <locale.h>
int main()
{
	setlocale(LC_CTYPE, "Polish");
	GameManager gm;

	gm.WriteMenuText();
	gm.Setup();
	gm.Run();

    return 0;
}
