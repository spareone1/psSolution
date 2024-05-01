#include <stdio.h>

int main() {
	int bx, by;
	int bxTime, byTime;
	int dx, dy;
	int dxTime, dyTime;
	int jx, jy;
	int btime = 0, dtime;
	int tempx, tempy, temp;

	scanf("%d %d ", &bx, &by);
	scanf("%d %d ", &dx, &dy);
	scanf("%d %d", &jx, &jy);

	bxTime = jx - bx;
	byTime = jy - by;

	bxTime = bxTime >= 0 ? bxTime : -bxTime;
	byTime = byTime >= 0 ? byTime : -byTime;
	
	if (bxTime != byTime) {
		if (bxTime > byTime) {
			tempx = bxTime;
			bxTime = byTime;
			temp = tempx - bxTime;
			btime = temp >= 0 ? temp : -temp;
		}
		else {
			tempy = byTime;
			byTime = bxTime;
			temp = tempy - byTime;
			btime = temp >= 0 ? temp : -temp;
		}
	}
	btime += bxTime;

	dxTime = jx - dx;
	dyTime = jy - dy;

	dxTime = dxTime >= 0 ? dxTime : -dxTime;
	dyTime = dyTime >= 0 ? dyTime : -dyTime;
	dtime = dxTime + dyTime;
	
	if (btime > dtime) {
		printf("daisy");
	}
	else if (btime < dtime) {
		printf("bessie");
	}
	else {
		printf("tie");
	}

	return 0;
}