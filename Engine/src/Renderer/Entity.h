#pragma once

class Entity
{
public:
	virtual void Draw() = 0;

protected:
	void setPosX(int x);
	void setPosY(int y);
	void setRotation(int rotation);

	int getPosX() const;
	int getPosY() const;
	int getRotation() const;

private:
	float x;
	float y;
	float rotation;

};