# PowerShell script to run windeployqt for madCodeHighlighter
# Automatically deploys madCodeHighlighter.exe with predefined arguments

# Path to Qt MinGW64 bin directory
$QtBinPath = "F:\Qt\6.8.3\mingw_64\bin"

# Check if windeployqt.exe exists
$windeployqt = "$QtBinPath\windeployqt.exe"
if (-not (Test-Path $windeployqt)) {
    Write-Host "Error: windeployqt.exe not found at $windeployqt" -ForegroundColor Red
    Write-Host "Please verify the Qt installation path." -ForegroundColor Red
    Pause
    exit 1
}

# Path to the executable
$exePath = "E:\Deploy\madCodeHighlighter\madCodeHighlighter.exe"

# Check if the executable exists
if (-not (Test-Path $exePath)) {
    Write-Host "Error: Executable not found at $exePath" -ForegroundColor Red
    Write-Host "Please verify the path to madCodeHighlighter.exe." -ForegroundColor Red
    Pause
    exit 1
}

# Add Qt bin path to PATH for this session
$env:Path = "$QtBinPath;" + $env:Path

# Predefined windeployqt arguments
$arguments = "--release --force $exePath"

# Run windeployqt with predefined arguments
try {
    Write-Host "Running: windeployqt $arguments" -ForegroundColor Green
    Invoke-Expression "windeployqt $arguments"
}
catch {
    Write-Host "Error executing windeployqt: $_" -ForegroundColor Red
}

# Pause to keep the window open if launched by double-click
Write-Host "`nPress any key to exit..."
$null = $Host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")