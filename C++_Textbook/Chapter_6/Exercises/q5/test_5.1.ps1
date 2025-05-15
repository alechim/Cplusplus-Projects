$testCases = @(1, 5, 10, 15, 20)
$failed = $false

Write-Host "Running Triangle of Stars Tests`n" -ForegroundColor Cyan

foreach ($case in $testCases) {
    Write-Host "Test Case: $case lines" -ForegroundColor Yellow
    Write-Host "----------------------------------------"
    if (Test-Path .\5.1.exe) {
        & .\5.1.exe $case
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