#pragma once

#include <memory>

class ObjectBase;

// �������ߐ錾
bool HitCheckStageAndPlayer(const std::shared_ptr<ObjectBase>& p, const std::shared_ptr<ObjectBase>& s);

void TorimaInitialize();
void TorimaUpdate(const std::shared_ptr<ObjectBase>& p);

bool GameClear(const std::shared_ptr<ObjectBase>& p);
bool GameOver(const std::shared_ptr<ObjectBase>& p);

void Draw();