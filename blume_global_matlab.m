
filePath = 'C:\Users\Bhawn\Downloads\Input.xlsx';

% Specify sheet names
sheetName1 = 'LOCATIONS';
sheetName2 = 'DEMANDS';
sheetName3 = 'VEHICLES';
sheetName4 = 'DISTANCE MATRIX';

% Read sheets as a table
Locations = readtable(filePath, 'ReadVariableNames', true, 'Sheet', sheetName1);
Demands = readtable(filePath, 'ReadVariableNames', true, 'Sheet', sheetName2);
Vehicles = readtable(filePath, 'ReadVariableNames', true, 'Sheet', sheetName3);
Distance_matrix = readtable(filePath, 'ReadVariableNames', true, 'Sheet', sheetName4);

% Group the table by the 'location' column and sum up the 'weights'
groupedTable = groupsummary(Demands, 'LOCATION', {'sum', 'sum','max','max'}, {'VOLUME_CUFT_', 'WEIGHT_LBS_','DELIVERY_START','DELIVERY_END'});

% Extract the relevant columns from the grouped table
locations = groupedTable.LOCATION;
summedWeights = groupedTable.sum_WEIGHT_LBS_;
summedVolumes = groupedTable.sum_VOLUME_CUFT_;
maxTimeStartValues = groupedTable.max_DELIVERY_START;
maxTimeEndValues = groupedTable.max_DELIVERY_END;

% Create a new matrix
Useful_Demand_Matrix = [locations, summedWeights,summedVolumes,maxTimeStartValues,maxTimeEndValues];

% Display the new matrix
disp('New Matrix with Unique Locations and Summed Weights:');
disp(Useful_Demand_Matrix);

% Replace all 0s with 1000
Distance_matrix{:,:}(Distance_matrix{:,:} == 0) = 1000;

% Extract IDs where sourced from column is equal to 1 , 2 and 3

W1 = Locations.ID(Locations.SOURCED_FROM == 1);
W2 = Locations.ID(Locations.SOURCED_FROM == 2);
W3 = Locations.ID(Locations.SOURCED_FROM == 3);


% Display the result
disp('IDs with sourced from Warehouse 1:');
disp(W1);
disp('IDs with sourced from Warehouse 2:');
disp(W2);
disp('IDs with sourced from Warehouse 3:');
disp(W3);
W1 = [1; W1]
W2 = [2; W2]
W3 = [3; W3]

% Extract the specified rows and columns
Matrix1 = Distance_matrix(W1, W1+1)
Matrix2 = Distance_matrix(W2, W2+1)
Matrix3 = Distance_matrix(W3, W3+1)


