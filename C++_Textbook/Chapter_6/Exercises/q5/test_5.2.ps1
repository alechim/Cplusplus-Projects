$testCases = @(
    @(10, 15, "A"),
    @(20, 25, "B"),
    @(5, 30, "C"),
    @(15, 10, "D")
)

Write-Host "Running Reference and Value Parameters Tests`n" -ForegroundColor Cyan

foreach ($case in $testCases) {
    $num1, $num2, $ch = $case
    Write-Host "Test Case: num1 = $num1, num2 = $num2, ch = $ch" -ForegroundColor Yellow
    Write-Host "----------------------------------------"
    if (Test-Path .\5.2.exe) {
        & .\5.2.exe $num1 $num2 $ch
        if ($LASTEXITCODE -ne 0) {
            Write-Host "Test Failed for case: $case" -ForegroundColor Red
            exit 1
        }
    } else {
        Write-Host "Executable not found. Build may have failed." -ForegroundColor Red
        exit 1
    }
    Write-Host "----------------------------------------`n"
}

Write-Host "All tests completed successfully." -ForegroundColor Green