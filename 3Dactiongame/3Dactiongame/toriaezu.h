#pragma once

class ModelBase;
class Stage;

// �������ߐ錾
bool HitCheckStageAndPlayer(ModelBase* p, Stage* colS);

void TorimaInitialize();
void TorimaUpdate(ModelBase* p);

bool GameClear(ModelBase* p);
bool GameOver(ModelBase* p);

void Draw();