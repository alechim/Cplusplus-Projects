function Run-TestCase {
    param (
        [string]$testCase
    )
    Write-Host "========================================"
    Write-Host "Test Case: $testCase" -ForegroundColor Cyan
    Write-Host "----------------------------------------"
    $output = & .\main.exe $testCase
    Write-Host $output -ForegroundColor Yellow
    Write-Host "========================================"
    Write-Host ""
}

$testCases = @(
    "madam",
    "abba",
    "22",
    "67876",
    "4442444",
    "trymeuemyrt"
)

Write-Host "`nRunning Palindrome Tests`n" -ForegroundColor Green

foreach ($case in $testCases) {
    Run-TestCase $case
}

Write-Host "All tests completed." -ForegroundColor Green