#pragma once

class GameObject {
protected:
	int position;	// 여기선 x좌표만 볼거임.
	char shape;		// 캐릭터 모양. 플레이어는 p 또는 q,  몬스터는 M, 코인은 C, 총알은 > 또는 <.

public:
	//GameObject();
	GameObject(int position, char shape);

	void move_l();
	void move_r();

	virtual bool collisionCheck() const;
	virtual void interaction(GameObject* go) = 0;

	virtual void update();
};