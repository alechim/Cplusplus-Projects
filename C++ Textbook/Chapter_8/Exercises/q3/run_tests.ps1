$testCases = @(
    # Test case 1: Normal array with largest at end
    "10 20 30 40 50 60 70 80 90 100",
    
    # Test case 2: Normal array with largest in middle
    "50 40 30 20 100 60 70 80 90 10",
    
    # Test case 3: Normal array with largest at start 
    "90 50 40 30 20 15 60 70 80 5",
    
    # Test case 4: Array with all identical values
    "42 42 42 42 42 42 42 42 42 42",
    
    # Test case 5: Array with negative numbers
    "-5 -10 -15 -20 -25 -30 -35 -40 -45 -50",
    
    # Test case 6: Mixed positive and negative
    "5 -10 15 -20 25 -30 35 -40 45 -50",
    
    # Test case 7: Array with very large numbers
    "9999 8888 7777 6666 5555 4444 3333 2222 1111 10000"
)

$expectedOutputs = @(
    "The largest value in the array is '100' and the index is '9'.",
    "The largest value in the array is '100' and the index is '4'.",
    "The largest value in the array is '90' and the index is '0'.",
    "The largest value in the array is '42' and the index is '0'.",
    "The largest value in the array is '-5' and the index is '0'.",
    "The largest value in the array is '45' and the index is '8'.",
    "The largest value in the array is '10000' and the index is '9'."
)

$failed = $false
$count = 0;

Write-Host "`nRunning Largest Index Tests`n" -ForeGroundColor Green

for($i = 0; $i -lt $testCases.Count; $i++)
{
    $case = $testCases[$i]
    $expected = $expectedOutputs[$i]
    
    Write-Host "Test Case $($i + 1): $case" -ForegroundColor Yellow
    Write-Host "Expected: $expected" -ForegroundColor Cyan
    Write-Host "----------------------------------------"
    
    if(Test-Path .\main.exe)
    {
        $argArray = $case -split ' '
        $output = & .\main.exe $argArray 2>&1 | Out-String
        $output = $output.Trim()
        
        if($output -ne $expected)
        {
            $failed = $true
            Write-Host "(-1) Test Failed: Output doesn't match expected result" -Foreground Red
            Write-Host "Actual: $output" -ForegroundColor White
            if($count -gt 0) 
            {
                $count--;
            }
            # Write-Host "Debug: Number of arguments passed: $($argArray.Count)" -ForegroundColor Magenta
        }
        else
        {
            Write-Host "(+1) Test Passed!" -Foreground Green
            $count++;
        }
    } 
    else 
    {
        Write-Host "Executable not found. Build may have failed." -Foreground Red
        exit 1
    }
    Write-Host "----------------------------------------"
}

if($failed)
{
    Write-Host "$(7 - $count) Tests Failed..." -ForegroundColor Red
    if($count -gt 0)
    {
        Write-Host "$count Tests Passed..." -ForegroundColor Green
    }
    exit 1
} else 
{
    Write-Host "All tests completed." -ForegroundColor Green
}