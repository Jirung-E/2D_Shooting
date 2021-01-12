#pragma once

class GameObject {
protected:
	int position;	// ���⼱ x��ǥ�� ������.
	char shape;		// ĳ���� ���. �÷��̾�� p �Ǵ� q,  ���ʹ� M, ������ C, �Ѿ��� > �Ǵ� <.

public:
	//GameObject();
	GameObject(int position, char shape);

	void move_l();
	void move_r();

	virtual bool collisionCheck() const;
	virtual void interaction(GameObject* go) = 0;

	virtual void update();
};