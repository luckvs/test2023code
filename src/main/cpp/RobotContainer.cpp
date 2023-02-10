// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: RobotContainer.

#include "RobotContainer.h"

#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/RunCommand.h>
#include <frc/smartdashboard/SmartDashboard.h>

RobotContainer* RobotContainer::m_robotContainer = NULL;

RobotContainer::RobotContainer() : m_autonomousCommand(&m_drive) {
    frc::SmartDashboard::PutData(&m_drive);

    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("Autonomous Command", new AutonomousCommand(&m_drive));
	
    ConfigureButtonBindings();

    // Set up default drive command
    m_drive.SetDefaultCommand(frc2::RunCommand(
        [this]
        {
            m_drive.Motivate(
                m_joystick.GetY(),
                m_joystick.GetX());
        },
         {&m_drive}));

    m_chooser.SetDefaultOption("Autonomous Command", new AutonomousCommand(&m_drive));
    frc::SmartDashboard::PutData("Auto Mode", &m_chooser);
}

RobotContainer* RobotContainer::GetInstance() {
    if (m_robotContainer == NULL) {
        m_robotContainer = new RobotContainer();
    }
    return(m_robotContainer);
}

void RobotContainer::ConfigureButtonBindings() {


// TODO: Swap Out to Trigger.OnTrue()
//m_controllerButton2.WhenHeld(ArmRaiseCommand(&m_arm), true); // Arm raise (2)
//m_controllerButton4.WhenHeld(ArmLowerCommand(&m_arm), true); // Arm lower (4)
//m_controllerButton5.WhenHeld(IntakeCommand(&m_claw), true); // Intake (5)
//m_controllerButton6.WhenHeld(ShootCommand(&m_claw), true); // Shoot (6)
}

frc::Joystick* RobotContainer::getJoystick() {
   return &m_joystick;
}
frc::XboxController* RobotContainer::getController() {
   return &m_controller;
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // The selected command will be run in autonomous
  return m_chooser.GetSelected();
}
