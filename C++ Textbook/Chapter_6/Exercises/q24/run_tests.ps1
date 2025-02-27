$testCases = @(
    @(-4, 0, 7, -11, 2, 0, 15, -6, 9, -3, 0, 8, -1, 14, -5, 0, 10, -8, 13, 6),
    @(0, -7, 12, 0, -9, 3, -2, 0, 5, -15, 8, 0, -1, 11, -4, 0, 6, -13, 9, -10),
    @(1, -2, 0, 3, -4, 5, -6, 0, 7, -8, 9, -10, 0, 11, -12, 13, -14, 0, 15, -16),
    @(20, -19, 18, -17, 16, -15, 14, -13, 12, -11, 10, -9, 8, -7, 6, -5, 4, -3, 2, -1)
)
$failed = $false

Write-Host "Running Classifying Numbers Tests" -ForegroundColor Cyan

foreach($case in $testCases){
    Write-Host "Test Case: $case" -ForegroundColor Yellow
    Write-Host "----------------------------------------"
    if (Test-Path .\main.exe) {
        & .\main.exe $case
        if ($LASTEXITCODE -ne 0) {
            $failed = $true
            Write-Host "Test Failed for case: $case" -ForegroundColor Red
            break
        }
    } else {
        Write-Host "Executable not found. Build may have failed." -ForegroundColor Red
        exit 1
    }
    Write-Host "----------------------------------------"
}

if ($failed) {
    Write-Host "Tests Failed" -ForegroundColor Red
    exit 1
} else {
    Write-Host "`nAll tests completed successfully." -ForegroundColor Green
}