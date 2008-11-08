// Copyright 2008 Cyrus Najmabadi
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import "LocationUtilities.h"

#import "Location.h"
#import "NetworkUtilities.h"
#import "Utilities.h"
#import "XmlElement.h"

@implementation LocationUtilities

+ (Location*) findLocationWithGeonames:(CLLocation*) location {
    CLLocationCoordinate2D coordinates = location.coordinate;
    double latitude = coordinates.latitude;
    double longitude = coordinates.longitude;
    NSString* url = [NSString stringWithFormat:@"http://ws.geonames.org/findNearbyPostalCodes?lat=%f&lng=%f&maxRows=1", latitude, longitude];

    XmlElement* geonamesElement = [NetworkUtilities xmlWithContentsOfAddress:url important:YES];
    XmlElement* codeElement = [geonamesElement element:@"code"];
    NSString* postalCode = [codeElement element:@"postalcode"].text;
    NSString* country = [codeElement element:@"countryCode"].text;

    if (postalCode.length == 0) {
        return nil;
    }

    if ([@"CA" isEqual:country]) {
        return nil;
    }

    NSString* city = [codeElement element:@"adminName1"].text;
    NSString* state = [codeElement element:@"adminCode1"].text;

    return [Location locationWithLatitude:latitude
                                longitude:longitude
                                  address:@""
                                     city:city
                                    state:state
                               postalCode:postalCode
                                  country:country];
}


+ (Location*) findLocationWithGeocoder:(CLLocation*) location {
    CLLocationCoordinate2D coordinates = location.coordinate;
    double latitude = coordinates.latitude;
    double longitude = coordinates.longitude;
    NSString* url = [NSString stringWithFormat:@"http://geocoder.ca/?latt=%f&longt=%f&geoit=xml&reverse=Reverse+GeoCode+it", latitude, longitude];

    XmlElement* geodataElement = [NetworkUtilities xmlWithContentsOfAddress:url
                                                                  important:YES];
    NSString* postalCode = [geodataElement element:@"postal"].text;
    if (postalCode.length == 0) {
        return nil;
    }

    NSString* city = [geodataElement element:@"city"].text;
    NSString* state = [geodataElement element:@"prov"].text;

    return [Location locationWithLatitude:latitude
                                longitude:longitude
                                  address:@""
                                     city:city
                                    state:state
                               postalCode:postalCode
                                  country:@"CA"];
}


+ (Location*) findLocation:(CLLocation*) location {
    Location* result = [self findLocationWithGeonames:location];
    if (result == nil) {
        result = [self findLocationWithGeocoder:location];
    }
    return result;
}

@end