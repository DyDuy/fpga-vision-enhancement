# Windows launcher; all compilation and SSH tools run in Ubuntu WSL.
$ErrorActionPreference = 'Stop'
$repoRoot = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../..'))
$forward = @($args)
if ($forward.Count -eq 0) { $forward = @('--help') }
for ($index = 0; $index -lt $forward.Count; $index++) {
    $isInput = ($index -gt 0 -and $forward[$index - 1] -eq '--run')
    $isBinary = ($index -eq 1 -and $forward[0] -eq 'check')
    if ($isInput -or $isBinary) {
        $value = [string]$forward[$index]
        if ($value -match '^[A-Za-z]:[\\/]' -or $value.StartsWith('\\')) {
            $translated = @(& wsl.exe -d Ubuntu --exec wslpath -a -u $value)
            if ($LASTEXITCODE -ne 0 -or $translated.Count -ne 1) {
                throw "Cannot translate Windows path into WSL: $value"
            }
            $forward[$index] = $translated[0].Trim()
        } else {
            $forward[$index] = $value.Replace('\', '/')
        }
    }
}
& wsl.exe -d Ubuntu --cd $repoRoot --exec bash software/hps/de1.sh @forward
exit $LASTEXITCODE

