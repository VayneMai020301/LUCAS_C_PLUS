#include "builder_example.h"

void builder_example::run()
{
	/* Khoi tao builder (Thanh phan nam giu tat ca nhung phuong thuc cho viec xay nha)*/
	ConcreteBuilder* builder = new ConcreteBuilder();

	/* Khoi tao Director (Dieu phoi viec xay nha, dinh hinh nhung cong viec can thiet cho viec xay nha */

	Director director(builder);
	director.constructionHouse_1();

	/* Lay ket qua cua viec Builder */
	House* house = builder->getHouse();
	house->show();

	/* Xay nha theo cach 2*/
	builder = new ConcreteBuilder();
	Director director1(builder);
	director1.constructionHouse_2();
	House* house1 = builder->getHouse();
	house1->show();

	/* Xay nha theo cach a 3 (Chi co mot cai ghe) */
	builder = new ConcreteBuilder();
	Director director2(builder);
	director2.constructionHouse_3();
	House* house2 = builder->getHouse();
	house2->show();


	delete builder;
	delete house;
	delete house1;
}
