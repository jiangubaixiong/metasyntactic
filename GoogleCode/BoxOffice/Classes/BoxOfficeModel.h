//
//  BoxOfficeModel.h
//  BoxOfficeApplication
//
//  Created by Cyrus Najmabadi on 4/26/08.
//  Copyright 2008 Metasyntactic. All rights reserved.
//

#import "PosterCache.h"
#import "TrailerCache.h"
#import "AddressLocationCache.h"
#import "ReviewCache.h"
#import "XmlElement.h"
#import "Theater.h"
#import "NotificationCenter.h"
#import "SearchCache.h"
#import "DataProvider.h"
#import "RatingsCache.h"

@interface BoxOfficeModel : NSObject {
    NotificationCenter* notificationCenter;

    PosterCache* posterCache;
    TrailerCache* trailerCache;
    AddressLocationCache* addressLocationCache;
    ReviewCache* reviewCache;
    SearchCache* SearchCache;
    RatingsCache* ratingsCache;

    NSInteger backgroundTaskCount;
    UIActivityIndicatorView* activityIndicatorView;
    UIView* activityView;

    NSInteger searchRadius;

    NSDictionary* movieMap;

    NSMutableArray* favoriteTheatersData;

    NSArray* dataProviders;
}

@property (retain) NotificationCenter* notificationCenter;

@property (retain) PosterCache* posterCache;
@property (retain) TrailerCache* trailerCache;
@property (retain) ReviewCache* reviewCache;
@property (retain) AddressLocationCache* addressLocationCache;
@property (retain) RatingsCache* ratingsCache;

@property (retain) UIActivityIndicatorView* activityIndicatorView;
@property (retain) UIView* activityView;
@property (readonly) NSInteger backgroundTaskCount;

@property (retain) NSDictionary* movieMap;
@property (retain) NSMutableArray* favoriteTheatersData;
@property (retain) NSArray* dataProviders;

+ (BoxOfficeModel*) modelWithCenter:(NotificationCenter*) notificationCenter;

+ (NSString*) version;

- (void) addBackgroundTask:(NSString*) description;
- (void) removeBackgroundTask:(NSString*) description;

- (id<DataProvider>) currentDataProvider;
- (NSInteger) dataProviderIndex;
- (void) setDataProviderIndex:(NSInteger) index;
- (BOOL) northAmericaDataProvider;
- (BOOL) unitedKingdomDataProvider;

- (NSInteger) ratingsProviderIndex;
- (void) setRatingsProviderIndex:(NSInteger) index;
- (BOOL) rottenTomatoesRatings;
- (BOOL) metacriticRatings;
- (BOOL) noRatings;
- (NSString*) currentRatingsProvider;
- (NSArray*) ratingsProviders;

- (NSInteger) selectedTabBarViewControllerIndex;
- (void) setSelectedTabBarViewControllerIndex:(NSInteger) index;

- (NSInteger) allMoviesSelectedSegmentIndex;
- (void) setAllMoviesSelectedSegmentIndex:(NSInteger) index;

- (BOOL) sortingMoviesByTitle;
- (BOOL) sortingMoviesByScore;
- (BOOL) sortingMoviesByReleaseDate;

- (NSInteger) allTheatersSelectedSegmentIndex;
- (void) setAllTheatersSelectedSegmentIndex:(NSInteger) index;

- (Movie*) currentlySelectedMovie;
- (Theater*) currentlySelectedTheater;
- (BOOL) currentlyShowingReviews;

- (void) setCurrentlyShowingReviews;
- (void) setCurrentlySelectedMovie:(Movie*) movie
                           theater:(Theater*) theater;

- (BOOL) autoUpdateLocation;
- (void) setAutoUpdateLocation:(BOOL) value;

- (NSString*) postalCode;
- (void) setPostalCode:(NSString*) postalCode;

- (NSInteger) searchRadius;
- (void) setSearchRadius:(NSInteger) searchRadius;

- (NSDate*) searchDate;
- (void) setSearchDate:(NSDate*) date;

- (NSArray*) movies;
- (NSArray*) theaters;

- (void) onProviderUpdated;
- (void) onRatingsUpdated;

- (UIImage*) posterForMovie:(Movie*) movie;
- (Location*) locationForAddress:(NSString*) address;
- (Location*) locationForPostalCode:(NSString*) postalCode;

- (NSMutableArray*) theatersShowingMovie:(Movie*) movie;
- (NSArray*) moviesAtTheater:(Theater*) theater;
- (NSArray*) moviePerformances:(Movie*) movie forTheater:(Theater*) theater;

- (NSDictionary*) theaterDistanceMap;
- (NSArray*) theatersInRange:(NSArray*) theaters;

NSInteger compareMoviesByScore(id t1, id t2, void *context);
NSInteger compareMoviesByReleaseDate(id t1, id t2, void *context);
NSInteger compareMoviesByTitle(id t1, id t2, void *context);
NSInteger compareTheatersByName(id t1, id t2, void *context);
NSInteger compareTheatersByDistance(id t1, id t2, void *context);

- (XmlElement*) getPersonDetails:(NSString*) identifier;
- (void) setPersonDetails:(NSString*) identifier element:(XmlElement*) element;

- (XmlElement*) getMovieDetails:(NSString*) identifier;
- (void) setMovieDetails:(NSString*) identifier element:(XmlElement*) element;

- (NSMutableDictionary*) getSearchDates;
- (NSMutableDictionary*) getSearchResults;

- (NSString*) synopsisForMovie:(Movie*) movie;
- (NSInteger) scoreForMovie:(Movie*) movie;

- (NSArray*) trailersForMovie:(Movie*) movie;
- (NSArray*) reviewsForMovie:(Movie*) movie;

- (NSMutableArray*) favoriteTheaters;
- (BOOL) isFavoriteTheater:(Theater*) theater;
- (void) addFavoriteTheater:(Theater*) theater;
- (void) removeFavoriteTheater:(Theater*) theater;

- (NSString*) noLocationInformationFound;

- (BOOL) useSmallFonts;
- (void) setUseSmallFonts:(BOOL) useSmallFonts;

+ (NSString*) SEARCH_DATES;
+ (NSString*) SEARCH_RESULTS;
+ (NSString*) SEARCH_RADIUS;
+ (NSString*) POSTAL_CODE;
+ (NSString*) CURRENTLY_SELECTED_MOVIE;
+ (NSString*) CURRENTLY_SELECTED_THEATER;
+ (NSString*) SELECTED_TAB_BAR_VIEW_CONTROLLER_INDEX;
+ (NSString*) ALL_MOVIES_SELECTED_SEGMENT_INDEX;
+ (NSString*) ALL_THEATERS_SELECTED_SEGMENT_INDEX;
+ (NSString*) FAVORITE_THEATERS;
+ (NSString*) CURRENTLY_SHOWING_REVIEWS;
+ (NSString*) SEARCH_DATE;
+ (NSString*) AUTO_UPDATE_LOCATION;
+ (NSString*) DATA_PROVIDER_INDEX;
+ (NSString*) RATINGS_PROVIDER_INDEX;
+ (NSString*) USE_NORMAL_FONTS;

@end