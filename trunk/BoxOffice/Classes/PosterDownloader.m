//
//  PosterDownloader.m
//  BoxOffice
//
//  Created by Cyrus Najmabadi on 5/3/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "PosterDownloader.h"
#import "XmlParser.h"
#import "XmlElement.h"
#import "DifferenceEngine.h"
#import "XmlSerializer.h"
#import "ImdbPosterDownloader.h"

@implementation PosterDownloader

@synthesize movie;

- (void) dealloc {
    self.movie = nil;
    [super dealloc];
}

- (id) initWithMovie:(Movie*) movie_ {
    if (self = [super init]) {
        self.movie = movie_;
    } 
    
    return self;
}

- (NSData*) go {
    return nil;
    NSData* data = [ImdbPosterDownloader download:self.movie];
    if (data != nil) {
        return data;
    }
    
    return nil;
}

+ (NSData*) download:(Movie*) movie {
    PosterDownloader* downloader = [[[PosterDownloader alloc] initWithMovie:movie] autorelease];
    return [downloader go];
}

@end
