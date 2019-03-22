//
//  NSURLSession+JSON.h
//  VectorSDK
//
//  Created by JohnO'Dwyer on 4/18/14.
//  Copyright (c) 2014 MapQuest. All rights reserved.
//

#if __has_feature(modules)
@import UIKit;
#else
#import <UIKit/UIKit.h>
#endif


extern NSString *const MQURLSessionErrorDomain;

enum {
    MQURLSessionErrorXMLData = 1000,
    MQURLSessionErrorImageData
};

@interface NSURLSession (MQ)

//Uses [NSURLSession sharedSession] to create the task
+ (NSURLSessionDataTask *)dataTaskWithRequest:(NSURLRequest *)urlRequest
                                      success:(void (^)(NSURLResponse *response, NSData *data))success
                                      failure:(void (^)(NSURLResponse *response, NSError *error))failure;

+ (NSURLSessionDataTask *)dataTaskWithSession:(NSURLSession *)session
                                      request:(NSURLRequest *)urlRequest
                                      success:(void (^)(NSURLResponse *response, NSData *data))success
                                      failure:(void (^)(NSURLResponse *response, NSError *error))failure;

//Uses [NSURLSession sharedSession] to create the task
+ (NSURLSessionDataTask *)jsonDataTaskWithRequest:(NSURLRequest *)urlRequest
                                          success:(void (^)(NSURLResponse *response, NSDictionary *json))success
                                          failure:(void (^)(NSURLResponse *response, NSError *error))failure;

+ (NSURLSessionDataTask *)jsonDataTaskWithSession:(NSURLSession *)session
                                          request:(NSURLRequest *)urlRequest
                                          success:(void (^)(NSURLResponse *response, NSDictionary *json))success
                                          failure:(void (^)(NSURLResponse *response, NSError *error))failure;

//Uses [NSURLSession sharedSession] to create the task
+ (NSURLSessionDataTask *)imageDataTaskWithRequest:(NSURLRequest *)urlRequest
                                           success:(void (^)(NSURLResponse *response, UIImage *image))success
                                           failure:(void (^)(NSURLResponse *response, NSError *error))failure;

+ (NSURLSessionDataTask *)imageDataTaskWithSession:(NSURLSession *)session
                                           request:(NSURLRequest *)urlRequest
                                           success:(void (^)(NSURLResponse *response, UIImage *image))success
                                           failure:(void (^)(NSURLResponse *response, NSError *error))failure;

//Uses [NSURLSession sharedSession] to create the task
+ (NSURLSessionDataTask *)xmlParserDataTaskWithRequest:(NSURLRequest *)urlRequest
                                               success:(void (^)(NSURLResponse *response, NSXMLParser *xmlParser))success
                                               failure:(void (^)(NSURLResponse *response, NSError *error))failure;

+ (NSURLSessionDataTask *)xmlParserDataTaskWithSession:(NSURLSession *)session
                                               request:(NSURLRequest *)urlRequest
                                               success:(void (^)(NSURLResponse *response, NSXMLParser *xmlParser))success
                                               failure:(void (^)(NSURLResponse *response, NSError *error))failure;
@end
