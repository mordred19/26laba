#include "sort.h"

void udtSwap(Udt *udt1, Udt *udt2)
{
	Udt tmp;

	tmp = *udt1;
	*udt1 = *udt2;
	*udt2 = tmp;
}

void udtSelectionSort(Udt *udt)
{
	const int cap = udtCapacity(udt);
	Udt sorted, tmp, tmp1;
	UDT_TYPE item;

	if (cap < 2)
	return;

	udtCreate(&sorted, cap);
	udtCreate(&tmp, cap);
	udtCreate(&tmp1, cap);

	while (!udtEmpty(udt))
	{
		udtPush(&tmp, udtTop(udt));
		udtPop(udt);
		while (!udtEmpty(udt))
		{
			item = udtTop(udt);
			udtPop(udt);
			if (item._key < udtTop(&tmp)._key)
			{
				udtPush(&tmp, item);
			}
			else
				udtPush(&tmp1, item);				
		}
		udtPush(&sorted, udtTop(&tmp));
		udtPop(&tmp);
		
		while(!udtEmpty(&tmp1))
		{			
			udtPush(&tmp, udtTop(&tmp1));
			udtPop(&tmp1);			
		}
	
		udtSwap(udt, &tmp);

	}
	udtSwap(udt, &sorted);
	udtDestroy(&sorted);
	udtDestroy(&tmp);
	udtDestroy(&tmp1);
}