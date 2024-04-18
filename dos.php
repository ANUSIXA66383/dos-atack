<?php
$website = readline('Enter the website: ');

while (true) {
    $context = stream_context_create(['http' => ['header' => "User-Agent: MyAgent/1.0\r\n"]]);
    $content = file_get_contents($website, false, $context);
    $http_response_header = $http_response_header;
    $response_code = substr($http_response_header[0], 9, 3);
    echo "Response code: ". $response_code. "\n";
}

?>