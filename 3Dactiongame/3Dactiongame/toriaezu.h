#pragma once

class ModelBase;
class Stage;

// ÌßÛÄÀ²ÌßéŒ¾
bool HitCheckStageAndPlayer(ModelBase* p, Stage* colS);

void TorimaInitialize();
void TorimaUpdate(ModelBase* p);

bool GameClear(ModelBase* p);
bool GameOver(ModelBase* p);

void Draw();