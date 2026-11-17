[CmdletBinding()]
param(
  [int]$Seed = 1,
  [string]$SimulatorCommand = '',
  [string]$ManifestOut = ''
)
$ErrorActionPreference = 'Stop'
$verification = (Resolve-Path (Join-Path $PSScriptRoot '..')).Path
$repo = (Resolve-Path (Join-Path $verification '../..')).Path
$stamp = (Get-Date).ToUniversalTime().ToString('yyyyMMddTHHmmssZ')
$run = if ($ManifestOut) { [IO.Path]::GetFullPath($ManifestOut) } else { Join-Path $verification "manifests/runs/${stamp}_seed${Seed}/run.json" }
$runDir = Split-Path $run -Parent
New-Item -ItemType Directory -Force $runDir | Out-Null
$check = Join-Path $verification 'scripts/check_contract.py'
$args = @($check, '--repo-root', $repo, '--manifest-out', $run)
$status = 'passed'
$exit = 0
& python @args
$exit = $LASTEXITCODE
if ($exit -ne 0) { $status = 'failed' }
if ($SimulatorCommand) {
  Add-Content -Path (Join-Path $runDir 'simulator-command.txt') -Value $SimulatorCommand
  Write-Warning 'Simulator execution is intentionally not automatic; command recorded for reviewed execution.'
}
if (Test-Path $run) {
  $doc = Get-Content -Raw $run | ConvertFrom-Json
  $doc | Add-Member -NotePropertyName seed -NotePropertyValue $Seed -Force
  $doc | Add-Member -NotePropertyName simulator_command -NotePropertyValue $SimulatorCommand -Force
  $doc | Add-Member -NotePropertyName runner_status -NotePropertyValue $status -Force
  $doc | ConvertTo-Json -Depth 8 | Set-Content -Encoding utf8 $run
}
exit $exit
