ThisBuild / organization := "research.vision"
ThisBuild / version := "1.0.0"
ThisBuild / scalaVersion := "2.12.13"

lazy val chiselVersion = "3.5.6"
lazy val chiselTestVersion = "0.5.6"

lazy val root = (project in file("."))
  .settings(
    name := "VisionAccelerator",
    scalacOptions ++= Seq(
      "-Xsource:2.11",
      "-language:reflectiveCalls",
      "-deprecation",
      "-feature",
      "-unchecked",
      "-Xcheckinit"
    ),
    addCompilerPlugin(
      "edu.berkeley.cs" % "chisel3-plugin" % chiselVersion cross CrossVersion.full
    ),
    libraryDependencies ++= Seq(
      "edu.berkeley.cs" %% "chisel3" % chiselVersion,
      "edu.berkeley.cs" %% "chiseltest" % chiselTestVersion % Test
    ),
    Test / parallelExecution := false,
    trapExit := false
  )

