$testCases = @(
    # Test Case 1: Simple Increasing
    "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20",

    # Test Case 2: All Zeros
    "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",

    # Test Case 3: Negative numbers
    "-5 -4 -3 -2 -1 0 1 2 3 4 5 6 7 8 9 10 -10 -9 -8 -7"
    
    # Test Case 4: Repeated numbers
    "42 42 42 42 42 7 7 7 7 7 0 0 0 0 0 99 99 99 99 99"
    
    # Test Case 5: Large numbers
    "1000 2000 3000 4000 5000 6000 7000 8000 9000 10000 -1000 -2000 -3000 -4000 -5000 -6000 -7000 -8000 -9000 -10000"
)

Write-Host "`nRunning 1-D and 2-D Array Manipulation Tests`n" -ForegroundColor Green

for($i = 0; $i -lt $testCases.Count; $i++)
{
    $case = $testCases[$i]
    $testNumber = $i + 1

    Write-Host "Test-Case $testNumber`: $case" -ForegroundColor Yellow
    Write-Host "----------------------------------------"

    if(Test-Path .\main.exe)
    {
        $argArray = $case -split ' '
        $output = & .\main.exe $argArray 2>&1 | Out-String
        $output = $output.Trim()

        # Expected output file path
        $expectedOutputFile = ".\Tests\expectedOutput$testNumber.txt"

        # Compare with expected output
        $expected = Get-Content -Path $expectedOutputFile -Raw
        $expected = $expected.Trim()

        if($output -eq $expected) 
        {
            Write-Host "Test Case $testNumber`: PASSED" -ForegroundColor Green
        } else 
        {
            Write-Host "Test Case $testNumber`: FAILED - Output doesn't match expected" -ForegroundColor Red
            
            # Create diff files for comparison
            $actualOutputFile = ".\Tests\actualOutput$testNumber.txt"
            $output | Out-File -FilePath $actualOutputFile
            
            Write-Host "Differences between expected and actual output:"
            Write-Host "----------------------------------------"
            
            # Show differences (basic version)
            $diffLines = Compare-Object (Get-Content $expectedOutputFile) (Get-Content $actualOutputFile)
            if($diffLines) 
            {
                foreach($line in $diffLines) 
                {
                    if($line.SideIndicator -eq "<=") 
                    {
                        Write-Host "Expected: $($line.InputObject)" -ForegroundColor Red
                    } else 
                    {
                        Write-Host "Actual: $($line.InputObject)" -ForegroundColor Green
                    }
                }
            }
            
            Write-Host "----------------------------------------"
            Write-Host "See files for full comparison:"
            Write-Host "Expected: $expectedOutputFile"
            Write-Host "Actual: $actualOutputFile"
        }
    } else {
        Write-Host "Executable not found. Build may have failed." -Foreground Red
        exit 1
    }
    Write-Host "----------------------------------------"
}

Write-Host "All tests completed." -ForegroundColor Green