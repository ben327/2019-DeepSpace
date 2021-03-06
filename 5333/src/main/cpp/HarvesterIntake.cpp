#include "HarvesterIntake.h"

void HarvesterIntake::IntakingPeriodic() {
  _config.motors.transmission->Set(1);
}

void HarvesterIntake::OuttakingPeriodic() {
  _config.motors.transmission->Set(-1);
}

void HarvesterIntake::DeployingPeriodic() {
  _config.motors.transmission->StopMotor();
}

void HarvesterIntake::StowingPeriodic() {
  _config.motors.transmission->StopMotor();
}

void HarvesterIntake::StowedPeriodic() {
  _config.motors.transmission->StopMotor(); // probably doesn't need this, but ~
}


void HarvesterIntakeController::Update(double dt) {
  if (_joy.GetRawButton(3)) {
    _harvesterIntake.SetIntaking();
  } else if (_joy.GetRawButton(5)) {
    _harvesterIntake.SetOuttaking();
  } else if (_joy.GetRawButton(11)) {
    _harvesterIntake.SetStowed();
  }

  _harvesterIntake.Update(dt);
}
