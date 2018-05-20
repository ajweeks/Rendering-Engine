#pragma once

#pragma warning(push, 0)
#include <LinearMath/btVector3.h>
#include <LinearMath/btScalar.h>
#pragma warning(pop)

#include <utility>
#include <set>

#include <BulletCollision/CollisionDispatch/btCollisionWorld.h>

class btDiscreteDynamicsWorld;
class btDynamicsWorld;
class btRigidBody;
class btCollisionObject;

namespace flex
{
	struct GameContext;

	class PhysicsWorld
	{
	public:
		PhysicsWorld();
		virtual ~PhysicsWorld();

		void Initialize(const GameContext& gameContext);
		void Destroy();

		void Update(sec deltaSeconds);

		btDiscreteDynamicsWorld* GetWorld();

		btVector3 GenerateRayFromScreenPos(const GameContext& gameContext, i32 x, i32 y);

		btRigidBody* PickBody(const btVector3& rayFromWorld, const btVector3& rayToWorld);

	private:
		friend void PhysicsInternalTickCallback(btDynamicsWorld *world, btScalar timeStep);

		btDiscreteDynamicsWorld * m_World = nullptr;

		static const u32 MAX_SUBSTEPS = 32;

		std::set<std::pair<const btCollisionObject*, const btCollisionObject*>> m_CollisionPairs;
	};

	void PhysicsInternalTickCallback(btDynamicsWorld *world, btScalar timeStep);
} // namespace flex
