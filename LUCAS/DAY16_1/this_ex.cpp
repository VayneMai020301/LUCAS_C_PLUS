#include "this_ex.h"

void this_ex::run()
{
	{
		/* Phan biet bien thanh vien va tham so */
		Person per("ABC");
		per.show();

		/* Chuoi  goi ham (MEthod Chaining) */
		Rectangle rec(0, 0);
		rec.setW(100).setH(300).setW(20).setH(2);
		rec.show();

		/* Tra ve doi tuog hien tai tu ham */

		Rectangle recCurrent = rec.getRectangle();
		recCurrent.show();
		cout << "Dia chi recCurrent: " << &recCurrent << endl;
		cout << "Dia chi rec: " << &rec << endl;
		/* So sanh hai doi tuong */
		recCurrent.Compare(rec);
		rec.Compare(recCurrent);

		recCurrent.Compare(recCurrent);
		rec.Compare(rec);
	}
	cout << "End this example" << endl;
}