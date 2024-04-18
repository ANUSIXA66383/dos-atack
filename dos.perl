use strict;
use warnings;
use LWP::Simple;
my $website = <STDIN>;
while (1) {
    
    chomp $website;
    my $response = get($website);
    print "Response code: ". ($response? $response->code : "Error"). "\n";
}   