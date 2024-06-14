#include "Components.h"
#include "Scene.h"

typedef std::vector<Component*> compVec;

void Meteor::OnAwaken()
{
	// this sucks
	rb = dynamic_cast<Rigidbody*>(gameObject->GetComponent(typeid(Rigidbody).name()));
	float randDrift = (((double)rand() - 100) / (RAND_MAX)) * drift - drift / 2;
	rb->AddForce(LeaVec2(randDrift, 0));
}

void Meteor::OnUpdate(double _deltaTime)
{
	if (rb->collidedLastFrame) {
		// just doing a height check
		if (gameObject->position.y < 30) {
			// hit player, destroy self
			gameObject->enabled = false;
		}
		else {
			// hit ground... you lose !!
			if (gameObject->scene->gamestate == Gamestate::Playing) {
				gameObject->enabled = false;
				gameObject->scene->gamestate = Gamestate::Lost;
				gameObject->scene->Instantiate("loseText", LeaVec2(-60, -40), LeaVec2(15, 15), compVec{
				new TextRenderer("Oh no! You lost!", 12) });
			}
		}
	}
}
